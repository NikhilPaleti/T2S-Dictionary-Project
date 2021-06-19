'
set speech = Wscript.CreateObject("SAPI.spVoice") 
Set speech.Voice = speech.GetVoices.Item(1)
speech.speak"the intellectual and practical activity encompassing the systematic study of the structure and behaviour of the physical and natural world through observation and experiment." 