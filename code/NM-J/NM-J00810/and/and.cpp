#include<bits/stdc++.h>
using namespace std;
long long a[20000010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,b,maxx=-1;
	cin>>n>>m;
	for(int i=0;i<n;i++){
        cin>>a[i];
	}
	if(m=1){
        for(int i=0;i<n;i++){
            if(a[i]>maxx) maxx=a[i];
        }
        cout<<maxx;
        return 0;
	}
	else if(m=2){
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                b=a[i]&a[j];
                if(maxx<b) maxx=b;
            }
        }
        cout<<maxx;
        return 0;
	}
	else if(m=n){
            maxx=a[0]&a[1];
        for(int i=2;i<n;i++){
            maxx=maxx&a[i];
        }
        cout<<maxx;
	}
	return 0;
}

