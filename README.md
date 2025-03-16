**Project title:** Bidirectional Visitor Counter by using I2C protocol


**Description:** Developed a Bidirectional Visitor Counter utilizing the I2C protocol with the LPC2129 microcontroller for real-time people counting. This system enhances automation, security, and energy efficiency in malls, offices, hospitals, and public spaces. The microcontroller processes sensor data to track entry and exit counts, displaying results on an LCD. Ideal for smart building automation, security monitoring, and crowd management.

#EmbeddedSystems #IoT #LPC2129 #I2C #Automation #Microcontroller #TechInnovation


**Requirments:**

**hardware:** Microcontroller, IR sensor - IRM393, EEPROM - AT24C08, RTC - DS1307, LCD, LED, Connecting wires

**software:** c,Embedded C

**Tools:** Keil uvision IDE, Flash magic


**Explanation:**

   The system consists of two IR sensors for monitoring entry and exit counts.
    When IR1 detects an object, it sends a signal to the microcontroller, which increases the entry count and updates the LCD display.
    When IR2 detects an object, the microcontroller increases the exit count and updates the display accordingly.
    
   The occupancy count is calculated based on IN and OUT counts:
        *If the occupancy count is greater than 0, the LED turns ON.
        *If the occupancy count is 0, the LED turns OFF.
   
   The real-time data (IN, OUT, and occupancy count) is stored in EEPROM, ensuring data retention.
   
   An RTC module (DS1307) resets the count values every 24 hours for accurate daily monitoring.


**uses:** 

1.power efficiency

2.crow management.


**Application:** 

   1. Automated Entry/Exit manageent
   
   2. Smart home automation
   
   3. Industrial workplace

**Future Enhacement:**
    
   Intergrate with  mobile application.
    
   AI-Based People Counting & Image Processing
