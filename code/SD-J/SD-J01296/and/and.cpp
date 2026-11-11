#include<iostream>
#include<cmath>
using namespace std;
long long temp,temp2,temp3,n,m,maxx,ans,xxx[40];
bool a[1000000][40],flag[1000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	xxx[0]=1;
	for(long long i=1;i<40;i++){
		xxx[i]=xxx[i-1]*2;
	}
	for(long long i=0;i<n;i++){
		temp2=0;
		cin>>temp;
		while(temp!=0){
			a[i][temp2]=temp%2;
			temp=temp>>1;
			maxx=max(temp2,maxx);
			temp2++;
		}
	}
	for(long long i=maxx;i>=0;i--){
		temp3=0;
		for(long long j=0;j<n;j++){
			if(!flag[j]&&a[j][i]==1){
				temp3++;
			}
		}
		//cout<<i<<"Î»"<<temp3<<"¸ö\n"; 
		if(temp3>=m){
			for(long long j=0;j<n;j++){
				if(!flag[j]&&a[j][i]!=1){
					flag[j]=1;
				}
			}
			ans+=xxx[i];
		}
	}
	cout<<ans;
	return 0;
}
