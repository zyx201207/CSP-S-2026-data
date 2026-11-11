#include <bits/stdc++.h>
using namespace std;
char c[2000000],l[600000005];
long long n,a[2000000];
long long lf,ri,num=0;
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			l[num]=c[i];
			num++;
		}
	}
	for(int i=0;i<num/2;i++){
		if(l[i]==l[num-i-1]){
			continue;
			cout<<i<<'/'<<num-i-1<<'\n';
		}else{
			ans++;
			
		}
	}
	cout<<ans;//why my some answer are zero? 
	return 0;
}
