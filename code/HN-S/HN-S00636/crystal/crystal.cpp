#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,cnt=0,c;
	int l=0;
	string a;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a;
	}
	for(int i=0;i<n;i++){//循环能量水晶的个数次 
		for(int j=0;j<a.size();j++){//标准的水晶
		c=m;
		l=0;
			for(int x=1;x<a.size();x++){
				if(a[x]<=a[j]){
					l=l+1;
					a[x]=a[i];
					c=c-a[j]-a[x];
					x++;
				}else{
					x++;
				}
				if(c<0){
					j++;
					break; 
				}
			}
		}
	}cout<<l;
	return 0;
}
