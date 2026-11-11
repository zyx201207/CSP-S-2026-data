#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200005],b[200005],c[200005],n=0,k=0;
ll s[200005];
int size(){
	int x=1,sum=0;
	while(s[x]!=0){
		x++;
		sum++;
	}
	return sum;
}
void pop(){
	s[size()]=0;
	return;
}
void push(ll x){
	s[size()+1]=x;
	return;
}
int head(){
	return s[size()];
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>b[i];
	}
	for(int i=1;i<n;i++){
		for(int j=i;j<=n;j++){
			if(a[b[j]]!=0){
				while(head()!=b[j]){
					a[head()]--;
					pop();
				}
				a[head()]--;
				pop();
				push(b[j]);
				a[b[j]]++;
			}else{
				push(b[j]);
				a[b[j]]++;
			}
		}
		for(int i=1;i<=k;i++){
			if(a[i]!=0){
				c[i]++;
			}
		}
		while(size()!=0){
			pop();
		}
	}
	cout<<c[1];
	for(int i=2;i<=k;i++){
		cout<<" "<<c[i];
	}
    return 0;
}