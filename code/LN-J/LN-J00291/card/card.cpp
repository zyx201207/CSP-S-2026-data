#include<iostream>
using namespace std;
const int N=5*1e5+10;
const int M=3*1e5+10;
int a[N];
int b[M];
int c[N];
void init(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    //freopen("card4.in","r",stdin);
    //freopen("card4.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int maxx=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>maxx){
            maxx=a[i];
        }
    }
    for(int i=0;i<n;i++){
        int p=0;
        for(int j=i;j<n;j++,p++){
            bool f=false;
            for(int k=0;k<p;k++){
                if(f){
                    c[k]=0;
                }
                if(c[k]==a[j]){
                    f=true;
                    p=k;
                }
            }
            c[p]=a[j];
            for(int i=0;i<n;i++){
                //cout<<c[i]<<" ";
            }
            //cout<<"\n";
        }
        //cout<<"\n";
        for(int j=0;j<p;j++){
            b[c[j]]++;
        }
        for(int j=0;j<p;j++){
            c[j]=0;
        }
    }
    for(int i=1;i<(maxx+1);i++){
        if(b[i]!=0){
            cout<<b[i]<<' ';
        }
    }
    return 0;
}
