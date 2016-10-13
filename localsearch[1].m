%Local search
clear
s=0.1;
xprev=rand(1);
yprev=sin(xprev*2*pi);
c=0;
a= [];
while c<=100;
    xnew=xprev+s;
    ynew=sin(xnew*2*pi);
    if ynew>yprev
        s=-s;
            else
        c=c+1;
    end
   xprev=xnew;
    yprev=ynew;
    %for i=1:c
     %   a(i)=xprev;
      %  b(i)=yprev;
    %end
end
disp(xprev)
disp(yprev)
%figure(1)
%plot(a)
%figure(2)
%plot(b)
