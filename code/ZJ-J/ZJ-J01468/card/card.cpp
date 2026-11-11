#include<iostream>
using namespace std;
struct fri{
	int num;
	int status=0;
}friends[300005];
struct barrel{
	int num=0;
	int cnt=1;
}t[500005];
int b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>friends[i].num;
	}
	for(int i=1;i<=n;i++){
		bool f=0;
		for(int j=i;j<=n;j++){
			t[friends[j].num].num++;
			if(t[friends[j].num].num>1){
				int t1=t[friends[j].num].cnt;
				friends[t1].status=-1;
				friends[j-1].status=-2;
			}
			t[friends[j].num].cnt=j;
		}
		for(int j=i;j<=n;j++){
			if(friends[j].status=-1)f=1;
			if(f=1&&friends[j-1].status!=-2)continue;
			f=0;
			b[friends[j].num]++;
		}
		for(int j=i;j<=n;j++){
			friends[j].status=0;
			t[j].num=0;
			t[j].cnt=1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
