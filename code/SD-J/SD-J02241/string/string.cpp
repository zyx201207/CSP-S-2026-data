#include<bits/stdc++.h>
using namespace std;
int n,a[200005],maxv;long long sum;char c[200005];bool test1;string temp;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
		maxv=max(maxv,a[i]);
	}
	if(maxv<=50){
		test1=1;
	}
	if(test1==1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++){
				temp+=c[i];
			}
		}
		long long ans=0;
		for(int i=0;i<temp.size();i++){
			if(i>temp.size()-i-1){
				break;
			}
			if(temp[i]!=temp[temp.size()-i-1]){
				ans++;
			}
		}
		cout<<ans;
	}else{
		long long ans=0;int lid=1,rid=n;
		while(1){
			if(a[lid]<a[rid]){
				if(c[lid]!=c[rid]){
					ans+=a[lid];
				}
				a[rid]-=a[lid];
				lid++;				
			}else if(a[lid]>a[rid]){
				if(c[lid]!=c[rid]){
					ans+=a[rid];
				}
				a[lid]-=a[rid];
				rid--;			
			}else{
				if(c[lid]!=c[rid]){
					ans+=a[rid];
				}
				a[lid]=0;
				a[rid]=0;
				lid++;
				rid--;			
			}
			if(lid>rid){
				break;
			}
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
