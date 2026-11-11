#include<bits/stdc++.h>
using namespace std;
int n;
struct nobe{
	long long a;
	char b;
}nb[10000000];
deque<int>pp;
int ex(){
	if(pp.size()==0){
		return 0;
	}else{
		return 1;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>nb[i].a>>nb[i].b;
		for(int j=0;j<nb[i].a;j++){
			pp.push_front(nb[i].b);
		}
	}
	int len;
	for(int i=0;i<n;i++){
		len+=nb[i].a;
	}
	int num=0;
	for(int i=0;i<len/2+1;i++){
		if(ex()==0){
			break;
		}
		if(pp.front()!=pp.back()){
			num++;
		}
		pp.pop_front();
		pp.pop_back();
	}
	cout<<num;
	return 0;
}



