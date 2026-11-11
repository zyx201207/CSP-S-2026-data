#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int l,r;
	char c;
}t[200005],l[200005],r[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int pos=0;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		t[i]={pos+1,pos+a,c};
		pos+=a;
	}
	int ll=0,rr=0;
	for(int i=1;i<=n;i++){
		ll++;
		if(t[i].r>=pos/2){
			l[ll]={t[i].l,pos/2,t[i].c};
			break;
		}
		else{
			l[ll]={t[i].l,t[i].r,t[i].c};
		}
	}
	for(int i=n;i>=1;i--){
		rr++;
		if(t[i].l<=pos-pos/2+1){
			r[rr]={pos-t[i].r+1,pos/2,t[i].c};
			break;
		}
		else{
			r[rr]={pos-t[i].r+1,pos-t[i].l+1,t[i].c};
		}
	}
/*	for(int i=1;i<=n;i++){
		cout<<t[i].l<<" "<<t[i].r<<" "<<t[i].c<<endl;
	}
	cout<<endl;
	for(int i=1;i<=ll;i++){
		cout<<l[i].l<<" "<<l[i].r<<" "<<l[i].c<<endl;
	}
	cout<<endl;
	for(int i=1;i<=rr;i++){
		cout<<r[i].l<<" "<<r[i].r<<" "<<r[i].c<<endl;
	}*/
	int anss=0;
	for(int i=1,j=1;i<=ll&&j<=rr;){
		if(r[j].r<l[i].r){
			anss+=(r[j].r-max(l[i].l,r[j].l)+1)*((int)(r[j].c!=l[i].c));
			j++;
		}
		else if(r[j].r==l[i].r){
			anss+=(r[j].r-max(l[i].l,r[j].l)+1)*((int)(r[j].c!=l[i].c));
			j++;
			i++;
		}
		else{
			anss+=(l[i].r-max(l[i].l,r[j].l)+1)*((int)(r[j].c!=l[i].c));
			i++;
		}
	}
	cout<<anss;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
