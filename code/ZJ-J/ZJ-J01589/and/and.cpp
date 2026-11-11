#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int n,m;
int a[maxn],t[maxn];
vector<int*> b;
//int cntk[30],cntd[30],del[maxn][30];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int t[35]={0};b.push_back(t);
		cin>>a[i];
		int cnt=0;
		while(a[i]!=0){
			b[i][cnt]=a[i]%2;
			if(a[i]/2==0){
				break;
			}
			a[i]/=2;
			cnt++;
		}
//		for(int j=cnt+1;j<30;j++){
//			del[cntd[j]++][j]=i;
//		}
	}
//	for(int i=0;i<30;i++){
//		cout<<"ABOUT "<<i<<endl;
//		cout<<cntk[i]<<" "<<cntd[i]<<endl;
//		for(int j=0;j<cntd[i];j++){
//			cout<<del[j][i]<<endl;
//		}
//	}
	int f=0;long long ans=0;
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=0;j<n;j++){
//			cout<<b[j][i]<<" ";
			if(b[j][i]==1){
				cnt++;
			}
		}
		if(cnt>=m){
			f=1;
			for(int j=0;j<n;j++){
				if(b[j][i]==0){
					b.erase(b.begin()+j);
				}
			}
		}else{
			f=0;
		}
		ans=ans*2+f;
	}
	cout<<ans;
}