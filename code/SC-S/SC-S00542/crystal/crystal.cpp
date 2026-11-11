#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long a,s;
	scanf("%d%d",&a,&s);
	long long as[a],zs=0;
	for(int i=0;i<a;i++){
		cin>>as[i];
	}
	sort(as,as+a-1);
	for(int i=0;i<a;i++){
		long long asd=s,zsd=0;
		if(i!=0){
			for(int q=i;q>=0;q--){
				if(as[i]<=as[q]+asd){
					asd=as[q]+asd-as[i];
					zsd+=1;
				}else if(as[q]!=as[i]&&asd==0){
					break;
				}
			}
		}
		if(zs<zsd){
			zs=zsd;
		}
	}
	cout<<zs;
	fclose(stdin);
	fclose(stdout);
	return 0;
}