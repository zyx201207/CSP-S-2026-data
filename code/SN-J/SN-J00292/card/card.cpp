#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n=0,m,cc,z;
	queue<int> v,x,y;
	cin>>n>>cc;
	int zl[cc],db[n],js[cc];
	bool flag[cc];
	int mm=cc;
	z=n;
	while(n){
		cin>>m;
		db[z-n]=m;
		v.push(m);
//		x.push(m);
		n--;
	}
	for(int i=1;i<cc;i++){
		zl[i-1]=i;
	}
	n=z;
	y=v;
	while(z){
		for(int i=n-z;i<n;i++){
			if(v.front()==db[i]){
				x.push(v.front());
				v=x;
				x.empty();
			}else{
				x.push(v.front());
				v.pop();
				v.push(zl[i+1]);
			}
		}
		
		while(!v.empty()){
			while(cc){
				if(v.front()==zl[cc-1]){
					js[cc-1]++;
				}
				cc--;
			}
			cc=mm;
			v.pop();
		}
		v=y;
		z--;
	}
	for(int i=0;i<cc;i++){
		cout<<js[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
} 
