#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long a,s;
    long long u=0;
	long long y[5005];
	cin>>a>>s;
    long long ma=1;
    if(a<5000){
        for(long long i=0;i<a;i++){
            cin>>y[i];
        }
        sort(y,y+a);
        long long l=1;
        long long x=0;
        long long c=0;
        for(long long i=1;i<a;i++){
            l++;
            c+=(y[i]-y[i-1]);
            if(c>s){
                c-=(y[x+1]-y[x]);
                x++;
                l--;
            }
            ma=max(ma,l);

        }



    }else{
        ma=a;

    }
    cout<<ma;

	return 0;
}
