#include<bits/stdc++.h>
using namespace std;
int n,a[100010],b[100010],cnt1=0;
long long m;//cnt1就是最多水晶数 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a+1,a+n+1);
	for(int j=1;n-j+1>cnt1;j++){//所有最小水晶后开始组合值 
		int t1=m;
		for(int i=j+1;i<n;i++){//开始模拟 
			int t2=0;
			if(t1-(b[i+1]-b[i]+b[i]-b[i-1])>=0){
				if(t2==0) t2=j;
				int v=0; 
				for(int k=t2;k<=i;k++){
					v+=(b[i+1]-b[k]);
				}
				if(t1-v>=0){//判断增加后超值没有 
					int cnt2=0;
					//cout<<t1<<'/' ;
						for(int k=t2;k<=i+1;k++){//没超值，从b[k]到b[i+1]相等 
							b[k]=b[i+1];
							cnt2++;
						}
					cnt1=max(cnt1,cnt2);
					t1-=v; 
				}else{
					int cnt3=0;
					for(int k=j;k<=i;k++){//超值，从b[k]到b[i]相等直接结束 
						cnt3++;
					}
					cnt1=max(cnt1,cnt3);
				}
			}
		}
		/*for(int s=1;s<=n;s++){
			cout<<b[s]<<' ';
		}
		cout<<endl;*/ 
		for(int s=1;s<=n;s++){
			b[s]=a[s];
		}
	}
	cout<<cnt1;
	return 0; 
} 
