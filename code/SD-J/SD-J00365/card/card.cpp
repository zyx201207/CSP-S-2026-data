#include<bits/stdc++.h>
using namespace std;
long long l=1,p[100010];
void pop(){
	cout<<p[l-1]<<endl;
	p[l-1]=0;
	l--;
}
void push(long long x){
	p[l]=x;
	cout<<" "<<p[l];
	l++;
}
long long pushback(){
	return p[l-1];
}
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout); 
	long long n,m;
	vector<long long> a(100010,0);
	vector<long long> b(100010,0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int o=i;o<=n;o++){
			for(int x=1;x<l;x++){
				if(p[x]==a[o]){
					for(int y=x;y<=l;y++){
						pop();
					}
					break;
				}
			}
		push(a[o]);
		}
		for(int o=1;o<=l;o++){
			b[o]++;
		}
		for(int o=1;o<=l;o++){
			pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
} 
