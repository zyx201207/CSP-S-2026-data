#include<bits/stdc++.h>
using namespace std;
struct sta{
	int pos;
	int time;
};
struct place{
	int start;
	int end;
};
int main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int a[m+5];  
	for(int i=1;i<=m;i++){
		cin>>a[i];
	} 
	int k,last;
	sta x[50005];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x[j].pos>>x[i].time;
			if(x[j].pos==x[j-1].pos){
				last=x[j].pos;
			}
		}
	}
	place r[q+5];
	for(int i=1;i<=q;i++){
		cin>>r[i].start>>r[i].end;
	}
	int ans[q+5];
	for(int i=1;i<=q;i++){
		sum
	}
	return 0;
}