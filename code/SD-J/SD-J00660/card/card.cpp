#include<bits/stdc++.h>
using namespace std;
int n,m,l=0,t=0,k=1;
int q[500010],a[500010]={0},b[500010]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	t=0;
	for(int w=0;w<n;w++){
		cin>>q[w];
	}
	for(int r=0;r<n;r++){
		for(int e=t;e<n;e++){
			for(int w=0;w<l;w++){
				if(q[e]==a[w]){
					l=w;
					break;
				}
			}
			l+=1;
			a[l-1]=q[e];
		}
		for(int w=0;w<l;w++){
			b[a[w]]++;
		}
		t++;
		l=0;
		for(int w=0;w<n;w++){
			a[w]=0;
		}
	}
	for(int w=1;w<n;w++){
		for(int e=0;e<n-w;e++){
			if(q[e]>q[e+1]){
				k=q[e];
				q[e]=q[e+1];
				q[e+1]=k;
			}
		}
	}
	k=1;
	for(int e=0;e<n;e++){
		for(int w=0;w<e;w++){
			if(q[e]==q[w]){
				k=0;
			}
		}
		if(k!=0){
			cout<<b[q[e]]<<" ";
		}
		k=1;		
	}	
	return 0;
}
