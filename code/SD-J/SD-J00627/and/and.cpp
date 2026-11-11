#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
struct stu{
	int a;
	int s;
}G[N];
bool cmp(stu f,stu l){
	return f.s>l.s;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>G[i].a;
	}
	for(int i=1;i<=n;i++){
		int j=30;
		while(j>=0){
			int t=G[i].a;
			if(t>=pow(2,j)){
				t-=pow(2,j);
				G[i].s++;
			}
			j--;
		}
	}
	sort(G+1,G+n+1,cmp);
	int sum=G[1].a;
	for(int i=1;i<=m;i++){
		sum=sum&G[i].a;
	}
	cout<<sum;
	return 0;
}

