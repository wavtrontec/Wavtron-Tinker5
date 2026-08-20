# Getting Started — Wavtron Tinker 5

This is the detailed setup guide referenced from the main README. If you've already read the [Getting Started section](../README.md#getting-started) there, this page adds driver installation and OS-specific detail.

---

## Windows Driver Setup (one-time)

WCHISPTool needs a driver to talk to the CH32X033 USB bootloader.

1. Download the CH372 driver package from WCH:
   `https://www.wch-ic.com/downloads/CH372DRV_ZIP.html`
2. Extract the ZIP
3. Navigate to the `DRIVER` folder
4. Right-click `CH375WDM.INF` → **Install**
   *(or run `SETUP.exe` inside the driver folder as Administrator)*
5. Confirmation should read: **"The driver is successfully Pre-installed in advance!"**

This is permanent — you only need to do this once per computer.

---

## macOS / Linux

WCHISPTool on macOS and Linux typically works without additional driver installation. If your board isn't detected:

- **macOS:** ensure you're using a genuine data-capable USB-C cable
- **Linux:** you may need udev rules for the WCH USB bootloader device (VID `4348`, PID `55E0`):
  ```
  # /etc/udev/rules.d/50-wch-isp.rules
  SUBSYSTEM=="usb", ATTRS{idVendor}=="4348", ATTRS{idProduct}=="55e0", MODE="0666"
  ```
  Then run: `sudo udevadm control --reload-rules && sudo udevadm trigger`

---

## Full Flashing Walkthrough

1. Write and verify your sketch compiles in Arduino IDE
2. **Sketch → Export Compiled Binary**
3. Locate the exported `.hex` file (usually in the sketch folder or a `build/` subfolder)
4. Open **WCHISPTool**
5. Set **Chip Series: CH32X03x**, **Chip Model: CH32X033F8P**, **Dnld Port: USB**
6. Hold **BOOT**, plug in USB (or tap RESET if already connected), release BOOT after 2–3 seconds
7. Click **Search** — board should appear in **Dev List**
8. Select the board
9. Click **"..."** next to Object File1, browse to your `.hex` file
10. Click **Download**
11. Wait for **"Succ: 1"** confirmation at the bottom of WCHISPTool

Your program is now running.

---

## Re-flashing

Every time you want to upload new code:

1. Export a new compiled binary from Arduino IDE
2. Re-enter bootloader mode (hold BOOT, tap RESET, release BOOT)
3. In WCHISPTool, click Search again if the board isn't already listed
4. Browse to the new `.hex` file
5. Click Download

---

*Back to [main README](../README.md)*
