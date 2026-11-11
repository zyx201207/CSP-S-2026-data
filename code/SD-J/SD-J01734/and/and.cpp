#include<iostream>
#include<cmath>
using namespace std;
int n,m,cnt=-1;
int num[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;++i){
		cin>>num[i];
	}
	if(m==1){
		for(int i=0;i<n;++i){
			cnt=max(cnt,num[i]);
		}
	}else if(m==2){
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				if(i!=j){
					cnt=max(cnt,num[i] & num[j]);
				}
			}
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
