
n=4;
m=8;
s=0;
f=y.^2;
%parent generation
for i=1:n;
    for j=1:m;
        x=rand(1);
        if x<0.5;
            X(i,j)=0;
        else
            X(i,j)=1;
        end
    end
end
%convert integer to binary 
  for i=1:n;
      d=m-4;
     % y=0;
      if X(i,1)==0;
          a=1;
      else
          a=-1;
      end
      for j=2:m-1
          if j<=6
              y=(X(i,j)*(2^d))+y;
              d=d-1;
          else
              y=y+((X(i,m-1)*2+X(i,m)/4));
          end
      end
      y=y*a; %determing sign of integer value
  end
  f(i)=y.^2;
  for i=1:4;
      s=s+f(i);
  end
  for i=1:4;
      d(i)=f(i)/s;
  end
   
     
  
  
  
  