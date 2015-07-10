int distance;
while((SensorValue[line1] > 2925 || SensorValue[line2] > 2925) && (SensorValue[line1] > 2925 || SensorValue[line3] > 2925) && (SensorValue[line2] > 2925 || SensorValue[line3] > 2925))
  {
    //Do all of the ball collecting stuff
  }
while(distance == -1)
  {
        zeropointturn(127, -1, true);
        waitmsec(100);
        distance = SensorValue[sonic];
  }
setmotorspeed(0);
float y1;
float y2;
float y3;
while (y2>y3 || y2>y1)
  {
    zeropointturn(50, -1, true);
    waitmsec(50);
    y1 = SensorValue[sonic];
    waitmsec(50);
    y2 = SensorValue[sonic];
    waitmsec(50);
    y3 = SensorValue[sonic];
  }
while (!(SensorValue[sonic] == y2))
  {
  zeropointturn(30, -1, false);
  }
setmotorspeed(0)
while (SensorValue[sonic] > 20)
  {
    setmotorspeed(80)
  }
  while (y2>y3 || y2>y1)
    {
      zeropointturn(50, -1, true);
      waitmsec(50);
      y1 = SensorValue[sonic];
      waitmsec(50);
      y2 = SensorValue[sonic];
      waitmsec(50);
      y3 = SensorValue[sonic];
    }
while (!(SensorValue[sonic] == y2))
  {
    zeropointturn(30, -1, false);
  }
setmotorspeed(0)
while (SensorValue[sonic] > 60)
  {
    setmotorspeed(80)
  }
