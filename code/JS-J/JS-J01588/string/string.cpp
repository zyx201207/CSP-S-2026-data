#include<bits/stdc++.h>
using namespace std;
long long n,a[214514];
char c[214514];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        if(c[i]==c[i-1]){
            a[i-1]+=a[i];
            i--;
            n--;
        }
    }
    long long ans=0;
    int i1=1,i2=n;
    while(i1<i2){
        //cout<<"a"<<endl;//**************
        if(a[i1]<a[i2]){
            //cout<<"f"<<endl;//*******************
            if(c[i1]==c[i2]){
                a[i2]-=a[i1];
                i1++;
                //cout<<"b"<<endl;//**************
                continue;
            }
            ans+=a[i1];
            //cout<<ans<<' '<<a[i1]<<'\n';//*******************
            a[i2]-=a[i1];
            i1++;
            continue;
        }
        if(a[i1]==a[i2]){
            if(c[i1]!=c[i2]){
                ans+=a[i1];
                //cout<<"e"<<endl;//*****************
            }
            if(i1+1<=i2-1){
                i1++;
                i2--;
                //cout<<"c"<<endl;//******************
                continue;
            }
            else{
                cout<<ans;
                return 0;
            }
        }
        if(a[i1]>a[i2]){
            //cout<<"g"<<endl;//***************
            if(c[i1]==c[i2]){
                a[i1]-=a[i2];
                i2--;
                //cout<<"d"<<endl;//******************
                continue;
            }
            ans+=a[i2];
            //cout<<ans<<' '<<a[i2]<<'\n';//*******************
            a[i1]-=a[i2];
            i2--;
            continue;
        }
    }
    cout<<ans;
	return 0;
}
/*
3
2 a
2 b
1 c
*/