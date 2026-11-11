#include<bits/stdc++.h>
using namespace std;
int x[200005];
char a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>x[i]>>a[i];
	}
	int r=1,l=n;
	long long cnt=0;
	while(r<l){
		if(x[r]!=x[l]){
			if(a[r]!=a[l]) cnt+=min(x[r],x[l]);
			if(x[r]>x[l]){
				x[r]-=x[l];
				x[l]=0;
				l--;
			}else if(x[r]<x[l]){
				x[l]-=x[r];
				x[r]=0;
				r++;
			}
		}else{
			if(a[r]!=a[l]){
				cnt+=x[r];
			}
			x[r]=0;
			x[l]=0;
			r++;
		    l--;
		}
	}
	cout<<cnt;
	return 0;
} 
