#include<bits/stdc++.h>
using namespace std;
//杨耀杰 SN-J00808 西安翱翔中学 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	struct v{
		int ai;
		char ci;
	}a[200009];
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].ai>>a[i].ci;
	}
	int l,r,ll,rr;
	l=1;
	r=n;
	long long ans=0;
	for(int i=1;i<=n-1;i++){
		if(a[l].ai>a[r].ai){
						//cout<<a[r].ai;
			if(a[l].ci!=a[r].ci)ans+=a[r].ai;
			a[l].ai-=a[r].ai;
			r--;
		}
		else if(a[l].ai<a[r].ai){
						//cout<<a[r].ai;
			if(a[l].ci!=a[r].ci)ans+=a[l].ai;
			a[r].ai-=a[l].ai;
			l++;
		}
		else {
			//cout<<l<<" "<<r<<" "<<ans;
			if(a[l].ci!=a[r].ci)ans+=a[l].ai;
			r--;
			l++;
			i++;
		}
		//cout<<ans;
	}
	cout<<ans;
	return 0;
}
