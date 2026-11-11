#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,a[200005],b,cnt[10000][10000],cnt1,res;
string s,s1;
double t;
bool vis[100000];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cnt[0][0]=a[0];
	for(int i=0;i<n;i++){
		cnt[cnt1][0]=a[i];
		for(int j=i+1;j<n;j++){
			cnt[cnt1][1]=a[j];
			cnt1++;
		}
		cnt1++;
	}
	for(int i=0;i<n;i++){
		
		for(int j=0;j<n;j++){
			cout<<cnt[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
