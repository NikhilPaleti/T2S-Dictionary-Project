'
set speech = Wscript.CreateObject("SAPI.spVoice") 
Set speech.Voice = speech.GetVoices.Item(1)
speech.speak "Welcome to the Mini Project of Team 69. We hope you like it"