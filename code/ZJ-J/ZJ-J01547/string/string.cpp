#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[200010];
char b[200010];
int c[200010],d[200010];
struct node{
	int x,y;
	char z;
	int id;
	int nxt;
}m[500010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >>a[i]>>b[i];
		c[i]=c[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		d[i]=d[i-1]+a[n-i+1];
	}
	int tot=1;
	int l=1,r=1;
	while(l<=n&&r<=n){
		if(c[l]<=d[r]){
			m[tot].x=c[l],m[tot].y=0,m[tot].z=b[l],m[tot].id=l;
			l++;
			tot++;
		}else{
			m[tot].x=d[r],m[tot].y=1,m[tot].z=b[n-r+1],m[tot].id=r;
			r++;
			tot++;
		}
	}
	while(l<=n){
		m[tot].x=c[l],m[tot].y=0,m[tot].z=b[l],m[tot].id=l;
		l++;
		tot++;
	}while(r<=n){
		m[tot].x=d[r],m[tot].y=1,m[tot].z=b[n-r+1],m[tot].id=r;
		r++;
		tot++;
	}
	for(int i=1;i<tot;i++){
		
		if(m[i].y==0){
			int j=i-1;
			while(m[j].x>c[m[i].id-1]){
				if(m[j].y==1){
					m[j].nxt=i;
				}j--;
			}
		}if(m[i].y==1){
			int j=i-1;
			while(m[j].x>d[m[i].id-1]){
				if(m[j].y==0){
					m[j].nxt=i;
				}j--;
			}
		}
	}
	int ans=0;
	for(int i=1;i<tot;i++){
		if(m[i].nxt){
			if(m[i].y==0&&m[i].z!=m[m[i].nxt].z){
				int len1=(d[m[m[i].nxt].id]-d[m[m[i].nxt].id-1]);
				int len2=(c[m[i].id]-c[m[i].id-1]);
				int lentot=d[m[m[i].nxt].id]-min(c[m[i].id-1],d[m[m[i].nxt].id-1]);
				ans+=len1+len2-lentot;
			}else if(m[i].y==1&&m[i].z!=m[m[i].nxt].z){
				int len1=(c[m[m[i].nxt].id]-c[m[m[i].nxt].id-1]);
				int len2=(d[m[i].id]-d[m[i].id-1]);
				int lentot=c[m[m[i].nxt].id]-min(d[m[i].id-1],c[m[m[i].nxt].id-1]);
				ans+=len1+len2-lentot;
			}
		}else{
			
		}
	}cout <<ans/2;
	return 0;
}
