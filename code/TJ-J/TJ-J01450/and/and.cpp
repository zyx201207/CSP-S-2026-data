#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int mx1=0,mx=0,mx2=0;
	if(m==1){
		cout<<a[n];
	}else{
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
			int s[m+2][100000]={0},x=a[i],t[m+1];
				for(int h=0;;h++){//a[i]的二进制字符串 已改 
					s[1][h]=x%2;
					x/=2;
					t[1]=h;
					if(x==0){
						break;
					}
				}
				int l=2;//除了a[i]以外的二进制字符串 已改 
				for(int g=j;g<=j+m;g++){
					x=a[j];
					for(int h=0;;h++){
						s[l][h]=x%2;
						x/=2;
						t[l]=h;
						if(x==0){
							break;
						}
					}
					l++;
				}
				for(int g=2;g<=m;g++){
					for(int o=0;o<=t[1];o++){
						if(s[1][o]!=s[g][o]){
							s[1][o]=0;
						}
					}
				}
				int r=1;
				if(s[1][0]==1){
					mx+=1;
				}
				for(int g=1;g<=t[1];g++){
					r*=2;
					if(s[1][g]==1){
						mx+=r ;
					}
				}
				mx2=mx;
				mx=0;
			}
				mx1=max(mx1,mx2);
		}
		cout<<mx1;
	}
	return 0;
} 
