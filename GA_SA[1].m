%SIMULATED ANNEALING
%FINDING MINIMUM VALUE 
clear
temp(1)=1;
N=1000;
for k=1:N
    en(k)=sin(k);
    temp(k+1)=1-(k/N);
end
s=round((rand(1))*N);
e=en(s);
sbest=s;
ebest=e;
temp1=temp(s);
for k=1:N
 r=round(rand(1));
    if r==0 && s<(N-100)
       snew=s+100;

    elseif r==1 && s>100
       snew=s-100;
    end

    enew=en(snew);
    if enew<e
        s=snew;
        e=enew;
    else if temp(k)>rand(1)
            s=snew;
            e=enew;
        end
        if enew<ebest
            ebest=enew;
            sbest=snew;
        end
    end
end
    %disp(sbest)
        disp(ebest)
        plot(en)





