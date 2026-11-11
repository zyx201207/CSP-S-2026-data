#include<bits/stdc++.h>
using namespace std;
struct stru{
	int numx,cs;
};
int li[500009];
int li2[500009];
//stack<int> st;
int main(){
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	int num,mnum;
	cin>>num>>mnum;
	if(mnum==1){
		cout<<((num+1)/2);
		return 0;
	}
	/*
	for(int i=0;i<num;i++){
		cin>>li[i];
	//	li2[i].numx=li[i];li2[i].cs=0;
	}*/
	for(int i=1;i<=mnum;i++){
		cout<<i<<" ";
	}
	/*
	for(int i=0;i<num;i++){
		int sz=0;
		for(int j=i;j<num;j++){
			int pd=0;
			for(int kk=0;k<=sz;k++){
				if(li2[kk]==li[j]) pd=1;
			}
			if(pd==1){
				int xx=0;
				while(li2[xx])
				li2[]
			} 
			li2[sz]        
		}
	}
	*/
	return 0;
}
//65 A   70  F 11
