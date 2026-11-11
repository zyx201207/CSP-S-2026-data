#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int n,mid,id,idl,idr,ans;
int a[maxn];
char c[maxn]={'A'};
int qzh[maxn],hzh[maxn];
int la[maxn],ra[maxn];
int lc[maxn],rc[maxn];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x; char ch; cin>>x>>ch;
		if(ch==c[id]) a[id]+=x;
		else a[++id]=x, c[id]=ch;
	}n=id;
	for(int i=1;i<=n;i++) qzh[i]=qzh[i-1]+a[i];
	for(int i=n;i>=1;i--) hzh[i]=hzh[i+1]+a[i];
	mid=(qzh[n]>>1)+qzh[n]%2;
//	cout<<mid<<" "<<qzh[n]<<"\n";
	id=0;
	for(int i=1;i<=n;i++){
		if(id==0&&qzh[i]>=mid){
			id=i;
		}
	}
//	cout<<"haha4";
	for(int i=n+1;i>=id+1+1;i--) a[i]=a[i-1],c[i]=c[i-1];
//	cout<<"hahh3";
	if(qzh[n]==mid*2) 
		a[id]=mid-qzh[id-1], c[id]=c[id],
		a[id+1]=qzh[id]-mid, c[id+1]=c[id];
	else 
		a[id]=mid-1-qzh[id-1], c[id]=c[id],
		a[id+1]=qzh[id]-mid, c[id+1]=c[id];
	n++;
//	cout<<"hahh2";
//	cout<<id<<"\n";
	for(int i=1,j=n;i<=id&&j>id;){
//		cout<<i<<" "<<j<<" \n";
		if(a[i]>a[j]){
//			cout<<"haha1"<<":\n  ";
			ra[++idr]=a[j], rc[idr]=c[j];
			la[++idl]=a[j], lc[idl]=c[i];
//			cout<<"la[++idl]="<<a[j]<<", ";
//			cout<<"ra[++idr]="<<a[j]<<", ";
//			cout<<"lc[++idl]="<<c[i]<<", ";
//			cout<<"rc[++idr]="<<c[j]<<";";
			a[i]-=a[j], a[j]=0, j--;
		}
		else if(a[i]==a[j]){
//			cout<<"haha2"<<":\n  ";
			ra[++idr]=a[j], rc[idr]=c[j];
			la[++idl]=a[i], lc[idl]=c[i];
//			cout<<"la[++idl]="<<a[j]<<", ";
//			cout<<"ra[++idr]="<<a[j]<<", ";
//			cout<<"lc[++idl]="<<c[i]<<", ";
//			cout<<"rc[++idr]="<<c[j]<<";";
			a[i]=0, a[j]=0, i++, j--;
		}
		else{
//			cout<<"haha3"<<":\n  ";
			ra[++idr]=a[i], rc[idr]=c[j];
			la[++idl]=a[i], lc[idl]=c[i];
//			cout<<"la[++idl]="<<a[i]<<", ";
//			cout<<"ra[++idr]="<<a[i]<<", ";
//			cout<<"lc[++idl]="<<c[i]<<", ";
//			cout<<"rc[++idr]="<<c[j]<<";";
			a[j]-=a[i], a[i]=0, i++; 
		}
//		cout<<i<<" "<<j<<"\n";
	}
//	cout<<"haha1";
	for(int i=1;i<=idl;i++){
//		cout<<la[i]<<" "<<lc[i]<<"    ";
//		cout<<ra[i]<<" "<<rc[i]<<"\n";
		if(lc[i]!=rc[i]) ans+=la[i];
	}
//	cout<<"haha0";
	cout<<ans;
}
