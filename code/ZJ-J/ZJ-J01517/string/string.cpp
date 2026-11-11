#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ls,md,s,s1,s2;
struct node{
	int num;char ch;
}a[200500];
stack<node>sk;
vector<node>v1,v2;
void erase(int p){
	for(int i=p;i<n;i++)a[i]=a[i+1];
	n--;
}
bool o;
signed main(){
  freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].ch;ls+=a[i].num;
	}
	md=(ls+1)/2;
	for(int i=1;i<=n;i++){
		if(ls%2==1&&s<=md&&md<=s+a[i].num){
			a[i].num--;o=1;
			if(!a[i].num)erase(i);
			break;
		}
		s+=a[i].num;
	}
	if(o){ls=0;for(int i=1;i<=n;i++)ls+=a[i].num;md=ls/2;}
	s=0;//cout<<md<<' ';
	for(int i=1;i<=n;i++){
		if(s<=md&&s+a[i].num>md){
			int p=md-s;
			if(p>0)sk.push({p,a[i].ch});
			if(a[i].num-p>0)v2.push_back({a[i].num-p,a[i].ch});
			o=0;s+=a[i].num;
			continue;
		}
		if(o)sk.push(a[i]);
		else v2.push_back(a[i]);
		s+=a[i].num;
	}
	while(sk.size()){
		v1.push_back(sk.top());
		sk.pop();
	}
//	for(int i=0;i<v1.size();i++){
//		cout<<v1[i].num<<' '<<v1[i].ch<<endl;
//	}
//	cout<<endl;
//	for(int i=0;i<v2.size();i++){
//		cout<<v2[i].num<<' '<<v2[i].ch<<endl;
//	}
	s=md;s1=0;s2=0;
	for(int i=0,j=0;i<v1.size()&&j<v2.size();){
	//	cout<<i<<' '<<j<<endl;
		s1=v1[i].num;s2=v2[j].num;
		if(v1[i].ch==v2[j].ch){
			int mn=min(v1[i].num,v2[j].num);
			s-=mn;v1[i].num-=mn;v2[j].num-=mn;
			if(v1[i].num==0)i++;
			if(v2[j].num==0)j++;
		}
		else {
			int mn=min(v1[i].num,v2[j].num);
			v1[i].num-=mn;v2[j].num-=mn;
			if(v1[i].num==0)i++;
			if(v2[j].num==0)j++;
		}
	}
	cout<<s;
	return 0;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/