# epd4in26_gray
Demo code to show grayscale for 4.26inch E-Paper from Waveshare and GDEQ0426T82
![image](/images/20240206_233135.jpg "image") 

## Hardware setup 
```
// Pin definition epdif.h
#define RST_PIN         8
#define DC_PIN          9
#define CS_PIN          10
#define BUSY_PIN        7
```

## Color definition

| Color | Reg 0x24 | Reg 0x26
| ----------- | ----------- | ---------|
| White | 0 | 0 |
| Light | 1 | 0 |
| Dark  | 0 | 1 |
| Black | 1 | 1 |

