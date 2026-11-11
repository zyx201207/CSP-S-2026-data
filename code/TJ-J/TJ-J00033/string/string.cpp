#include<iostream>
#include<cstdio>
using namespace std;
const int N=2e5+7;
int id[N],n;
long long sum;
char c[N];
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>id[i]>>c[i];
		sum+=id[i];
	}
	long long ans=0,cnt=0;
	for(int i=1,j=n;i<=j;){
		cnt+=min(id[i],id[j]);
		if(c[i]!=c[j]){
			ans+=min(id[i],id[j]);
			if(id[i]<id[j]){
				id[j]-=id[i];
				i++;
			}
			else if(id[i]==id[j]){
				i++,j--;
			}
			else{
				id[i]-=id[j];j--;
			}
		}
		else{
			if(id[i]<id[j]){
				id[j]-=id[i];
				i++;
			}
			else if(id[i]==id[j]){
				i++,j--;
			}
			else{
				id[i]-=id[j];j--;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
