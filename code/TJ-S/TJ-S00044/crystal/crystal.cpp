#include <bits/stdc++.h>
using namespace std;

int a[5000000];
int a1[5000000];
int fsa[5000000];

bool cmp(int x, int y){
	return x>y;
}

#define int long long
signed main(){
	freopen("crystal.in","w",stdin);
	freopen("crystal.out","r",stdout);
	int n,m;
	int zs=0;
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	
	sort(a+1, a+n+1);
	
	int dyzs=0;
	for(int i=1; i<=n; i++){
		if(a[i]>0){
			a1[i]=a1[i-1]+a[i];
			if(dyzs==0)dyzs=i;
//			cout<<a[i]<<" "<<i<<"  ";yhxiuyfduy8mufgvbgfbfgb
		} 
	} 
//	cout<<dyzs;bfgdsjxyudiyxiufybiufkyxu
	sort(a+1, a+dyzs, cmp);
	for(int i=1; i<dyzs; i++){
		fsa[i]=fsa[i-1]-a[i];
//		cout<<a[i]<<" ";fbfgmngfh
//		cout<<fsa[i]<<"   ";cfgnchgm
	}
	
	int ans=0;
	int c=1;
	for(int i=2; i<=n; i++){
		if(a[i] == a[i-1]){
			c++;
		}else{
			if(ans<c) ans=c;
			c=1;
		}
	}
	
	int b=1;
	if(m==0){
		cout<<ans;
	}else{
		for(int i=n; i>0; i--){
//			cout<<i<<endl; fsdhtyjdgioeujfoiujoieruro
			for(int j=ans+1; j<=n; j++){
				if(j*a[i]-a1[i] > m){
					if(j-1>ans){
						ans=j-1;
					}
//					cout<<i<<endl;hcgchc
					break;
				}else if(i-j+1<dyzs){
					if(dyzs-(i-j+1)<dyzs){
						if(fsa[dyzs-(i-j+1)]+(dyzs-(i-j+1))*a[i]+(i-dyzs+1)*a[i]-a1[i] > m){
							if(j-1>ans){
								ans=j-1;
//								cout<<i<<endl;hgccccccnghmjm
								break;
							}	
						}
					}else if(j-1>ans){
						ans=j-1;
						b=0;
//						cout<<j<<" "<<i;mhmjhmh
//						cout<<i<<endl;hmhhgmmghmh
						break;
					}
				}
			} 
			if(!b) break;
		}
	}
	
	cout<<ans;
	
	return 0;
} 
