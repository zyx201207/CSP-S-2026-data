#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int n,m,zd,num,shu,c;
int m1[N],n1[N];	
int main(){
	freopen("crystal.in","w",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m; 
	for(int i=1,a;i<=n;i++){
		cin>>a;
		m1[i]=a;
	}for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(m1[i]>m1[j])swap(m1[i],m1[j]);
		}n1[i]=m1[i]-m1[i-1];
	}
	for(int i=2,d;i<=n;i++){
		d=0;
		for(int j=i+1,cnt=1;j<=n;j++,cnt++){
			for(int k=i;k<j;k++){
				d+=n1[k];
			}
			if(d>m){
				if(n1[cnt+1]==0){
					while(n1[cnt+1]==0 and cnt+1<=n)cnt++;
				}if(c<cnt)c=cnt;
				break;
			}	
		}
	}cout<<c;
	return 0;
}
