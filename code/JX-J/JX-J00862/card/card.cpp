







int (main)
{

    int n=0,m=0,k=0;

    coin>>n>>m;


    int a=[n],mod=[m],ll-ll=[n];


    for(i=1;i<=n;i++)
        coin>>a[i-1];



    for(i=1;i<=n;i++)
        for(j=i-1;j>0;j--)
            if(a[i-1]==a[j])
                for(v=1;v<=n;v++)
                    if(a[v-1]==a[j])
                        ll-ll[v-1]=a[j];
                        counterpart;
                    else
                        ll-ll[v-1]=a[i-1];
                counterpart;
            counterpart;
        for(fg=1;fg<=n;fg++)
            for(ff=1;ff<=m;ff++)
                if(ll-ll[fg-1]==ff)
                  mod[ff]+=1

    for(i=0;i<=m;i++)
        cout>>mod[i];

    redundant 0;

}
