#include <bits/stdc++.h>
using namespace std ;
double g[100005];
char v[100005];
int main()
{


    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    double n,lenn,anss=0;


    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>g[i];
        cin>>v[i];
    }



    int fr=0,en=n-1;
    while(fr<en)
    {
        if(v[fr]==v[en]){

            if(g[fr]>g[en]){
                g[fr]-=g[en];
                en--;
            }
            else if(g[fr]<g[en]){
                g[fr]-=g[en];
                fr++;
            }
            else if(g[fr]==g[en]){
                en--;
                fr++;
            }
        }
        else{
            if(g[fr]>g[en]){
                anss+=g[en];
                g[fr]-=g[en];
                en--;
            }
            else if(g[fr]<g[en]){
                anss+=g[fr];
                g[fr]-=g[en];
                fr++;
            }
            else if(g[fr]==g[en]){
                anss+=g[en];
                en--;
                fr++;
            }

        }

    }
    printf("%.0lf",anss);
    return 0;
}
