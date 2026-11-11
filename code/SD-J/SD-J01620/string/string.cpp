#include<bits/stdc++.h>
using namespace std;

struct range{
	long long l,r;
}rag[26][200001];

int k[26];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ai,len=0,ans=0;
	char ci;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ai>>ci;
		k[int(ci)-int('a')]++;
		rag[int(ci)-int('a')][k[int(ci)-int('a')]].l=len+1;
		rag[int(ci)-int('a')][k[int(ci)-int('a')]].r=len+ai;
		len+=ai;
	}
	for(int i=0;i<26;i++){
		for(int j=1;j<=k[i];j++){
			int ansl=-1,ansr=-1,l,r,mid;
			l=1;
			r=k[i];
			while(l<=r){
				mid=(l+r)/2;
				if(rag[i][mid].l<=len-rag[i][j].l+1){
					l=mid+1;
					ansr=mid;
				}
				else r=mid-1;
			}
			l=1;
			r=k[i];
			while(l<=r){
				mid=(l+r)/2;
				if(rag[i][mid].r>=len-rag[i][j].r+1){
					r=mid-1;
					ansl=mid;
				}
				else l=mid+1;
			}
			if(rag[i][ansl].l>len-rag[i][j].l+1||rag[i][ansr].r<len-rag[i][j].r+1) continue;
			for(int k=ansl;k<=ansr;k++){
				if(rag[i][k].r>=len-rag[i][j].l+1&&rag[i][k].l<=len-rag[i][j].r+1) ans+=rag[i][j].r-rag[i][j].l+1;
				else if(rag[i][k].r>=len-rag[i][j].l+1&&rag[i][k].l>len-rag[i][j].r+1) ans+=(len-rag[i][j].l+1)-rag[i][k].l+1;
				else if(rag[i][k].r<len-rag[i][j].l+1&&rag[i][k].l<=len-rag[i][j].r+1) ans+=rag[i][k].r-(len-rag[i][j].r+1)+1;
				else if(rag[i][k].r<len-rag[i][j].l+1&&rag[i][k].l>len-rag[i][j].r+1) ans+=rag[i][k].r-rag[i][k].l+1;
			}
		}
	}
	cout<<len/2-ans/2;
}
