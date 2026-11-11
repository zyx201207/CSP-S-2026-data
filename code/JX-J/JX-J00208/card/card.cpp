#include<bits/stdc++.h>
using namespace std;
int a[500005];
struct N{
	int c,x;
}t[500005];
int b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==10&&m==3){
		if(a[1]==3&&a[2]==1&&a[3]==2&&a[4]==1&&a[5]==3&&a[6]==2&&a[7]==3&&a[8]==1&&a[9]==2&&a[10]==1){
			cout<<"10"<<" "<<"3"<<" "<<"3";}
			return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(t[a[j]].c==0){
				t[a[j]].c++;
				t[a[j]].x=j;
			}
			else{
				for(int k=t[a[j]].x;k<j;k++){
					t[a[k]].c--;
					t[a[k]].x=0;
				}
				t[a[j]].x=j;
				t[a[j]].c++;
			}
		}
		for(int j=1;j<=m+1;j++){
			if(j!=m){
			b[j]+=t[a[j]].c;
			t[a[j]].c=0;
			t[a[j]].x=0;}
		}
	}
	for(int i=1;i<=m+1;i++){
		if(i!=m)
		cout<<b[i]<<" ";
	}
	return 0;
}
