//SN-J00779 王梓翰 西安交通大学附属中学
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int arrays[25]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576};
int n,m; 
int dp[1048580];
int a[N];
int ans;
bool checkA=1;
bool checkB=0;
bool checkC=1;
int main(void){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	
	if(n>2000){
		for(int i=0;i<=20;i++){
			if(n==arrays[i]){
				checkB=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(n>2000){
			if(checkA){
				bool tmp=0;
				for(int j=0;j<=20;j++){
					if(a[i]==arrays[j]){
						tmp=1;
						break;
					}
				} 
				if(!tmp) checkA=0;
			}
			
			if(checkB){
				if(a[i]!=i-1){
					checkB=0;
				} 
			}
			if(checkC){
				if(a[i]!=4){
					checkC=0;
				}
			}
		}
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(m==2){
		sort(a+1,a+n+1);
		for(int i=n;i>=1;i--){
			for(int j=i-1;j>=1;j--){
				if(a[i]&a[j]){
					cout<<(a[i]&a[j]);
					return 0;
				}
			}
		}
		return 0;
	}
	if(n>2000){
		if(checkA){
			sort(a+1,a+n+1);
			cout<<a[n-m+1];
		}else if(checkB){
			cout<<n-m;
		}else if(checkC){
			sort(a+1,a+n+1);
			cout<<a[n-m+1];
		}
		return 0;
	}
	int s=1<<n;
	int maxi=0,maxj;
	for(int i=1;i<=n;i++){
		if(a[i]>maxi){
			maxi=a[i];
			maxj=i;
		}
	}
	for(int i=0;i<s;i++){
		int cnt=maxi;
		for(int j=1;j<=n;j++){
			if(j==maxj) continue;
			int now=1<<j;
			if(now&s){
				cnt&=a[j];
			}
//			cout<<i<<" "<<j<<" "<<cnt<<" "<<a[j]<<endl;
		}
//		cout<<cnt<<endl;
		ans=max(ans,cnt);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//T3 : Y3110W+/GR33N 
//mind(10:40)=abs(sin(tan(sqrt(x)+1145)+1919)-1145141919810)
//理论75pts(50pts特殊情况) 
