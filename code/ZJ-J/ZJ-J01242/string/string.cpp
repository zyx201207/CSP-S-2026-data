#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct ST{
	int a;
	char c;
};
ST l[100005];
ST r[100005];
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,lsum=0,rsum=0,m=0,lcnt=0,rcnt=0,sum=0;
	bool b;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		m+=a[i];
	}
	for(int i=1;i<=n;i++){
		if(lsum+a[i]<=m/2){
			lcnt++;
			lsum+=a[i];
			l[lcnt].a=a[i];
			l[lcnt].c=c[i];
		}
		else if(lsum+a[i]>m/2&&lsum<m/2){
			lcnt++;
			rcnt++;
			l[lcnt].a=m/2-lsum;
			lsum=m/2;
			l[lcnt].c=c[i];
			r[rcnt].a=a[i]-l[lcnt].a;
			r[rcnt].c=c[i];
		}
		else{
			rcnt++;
			r[rcnt].a=a[i];
			r[rcnt].c=c[i];
		}
	}
	for(int i=1;i<=lcnt;){
		b=l[i].c==r[rcnt].c;
		if(l[i].a>r[rcnt].a){
			if(!b){
				sum+=r[rcnt].a;
			}
			l[i].a-=r[rcnt].a;
			rcnt--;
		}
		else if(l[i].a<r[rcnt].a){
			if(!b){
				sum+=l[i].a;
			}
			r[rcnt].a-=l[i].a;
			i++;
		}
		else{
			if(!b){
				sum+=l[i].a;
			}
			r[rcnt].a-=l[i].a;
			i++;
			rcnt--;
		}
	}
	cout<<sum;
	return 0;
}
