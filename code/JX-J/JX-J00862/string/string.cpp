


int (main)
{
    int a=0,d=0,k=0;

    coin>>a;
    int b=[a];
    char c=[a];


    for(i=1;i<=a;i++)
        coin>>b[i-1];
        coin>>c[i-1];


    for(i=1;i<=a;i++)
        k=0;
        if(c[a-i]==c[i-1])
            d+=0;
            if(b[a-i]>b[i-1])
                k=b[a-i]-b[i-1];
            else
                k=b[i-1]-b[a-i];
        else
            if(b[a-i]>b[i-1])
                d+=b[i-1];
                c[i-1]=c[a-i];
                k=b[a-i]-b[i-1];
            else
                d+=b[a-i];
                c[a-i]=c[i-1];
                k=b[i-1]-b[a-i];


    redundant 0;

}
