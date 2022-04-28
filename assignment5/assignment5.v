module assign5_lavanya(
input  wire a,
input  wire b,
input  wire c,
output wire redled,
output wire greenled,
output wire blueled
);

reg x,y;
always @(*)
begin
x=(b|(!c))&((!a)|b);
y= (a|b|(!c))&((!a)|b|c)&((!a)|b|(!c));
if(x==1)
begin
redled=1;
end
else
begin
redled=0;
end
if(y==1)
begin
greenled=1;
end
else
begin
greenled=0;
end
if(x==y)
begin
blueled=1;
end
else
begin
blueled=0;
end
end
endmodule
