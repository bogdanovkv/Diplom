 program fileeditor;
 uses crt;
 const
  tse=[13,32,10,9];
  chis=['0'..'9'];
  yes=['y','Y','�','�'];
  no=['n','N','�','�'];
 var
  kir, lat: set of char;
  a,b,c: char;
  eng,rus,cif,rep,d: integer;
  fl_01,fl_02: file of char;
 begin
  repeat
   clrscr;
   eng:=0;
   rus:=0;
   cif:=0;
   rep:=0;
   kir:=['�'..'�','�'..'�'];
   lat:=['a'..'z','A'..'Z'];
   assign(fl_01,'C:\Pascal\Files\Fl_01.txt');
   assign(fl_02,'C:\Pascal\Files\Temp.txt');
   reset (fl_01);
   rewrite(fl_02);
   while not eof(fl_01) do
    begin
    read (fl_01, b);
    if b in kir then rus:=rus+1;
    if b in lat then eng:=eng+1;
    if b in chis then cif:=cif+1;
    if ((a<>b) and not (ord(b) in tse)) then
     write(fl_02,b)
     else rep:=rep+1;
    a:=b;
    end;
   writeln('Size of parent file: ',filesize(fl_01),' byte');
   writeln('Size of final file: ',filesize(fl_02),' byte');
   writeln('Quantity of english characters: ',eng);
   writeln('Quantity of russian characters: ',rus);
   writeln('Quantity of digits: ',cif);
   writeln('Quantity of repeatings ',rep);
   close(fl_01);
   close(fl_02);
   repeat
    writeln('Repeat?');
    readln(c);
    until ((c in yes) or (c in no));
  until not (c in yes);
 end.
