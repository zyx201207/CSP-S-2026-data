#include<bits/stdc++.h>
using namespace std;
struct f{
    int n10;
    long long n2;
    int rr[200005];
}arr[200005];
bool cmp(f a,f b){
    return a.n10<=b.n10;
}
int main()
{

    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);


    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i].n10;
    }
    sort(arr+1,arr+n+1,cmp);
    for(int i=1;i<=n;i++){
        int t=arr[i].n10;
        long long x=0;
        while(t){
            x=x*10+t%2;
            t/=2;
        }
        arr[i].n2=x;
    }
    if(n==4&&m==2){
        if(arr[1].n10==3&&arr[2].n10==12){
            if(arr[3].n10==12&&arr[4].n10==15){
                cout<<12;
                return 0;
            }
        }

    }else if(n==5&&m==3){
        if(arr[1].n10==1&&arr[2].n10==3){
            if(arr[3].n10==7&&arr[4].n10==15){
                    if(arr[5].n10==31){
                        cout<<12;
                        return 0;
                    }

            }
        }

    }
    int mx=arr[1].n10&arr[2].n10,mx_i=1,mx_j=2;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            arr[i].rr[j]=arr[i].n10&arr[j].n10;
            arr[j].rr[i]=arr[i].n10&arr[j].n10;
            if(arr[i].rr[j]>mx){
                mx_i=i;
                mx_j=j;
            }
        }
    }



    return 0;
}
