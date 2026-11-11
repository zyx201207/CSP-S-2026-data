#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;

int x,n,m,t,num;
vector<int> a;
vector<bool> is;

int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> x;
		a.push_back(x);
		is.push_back(0);
	}
	for(int i=0;i<a.size()-1;i++){
		for(int j=0;j<a.size()-1;j++){
			if(a[j] > a[j+1]) swap(a[j],a[j+1]);
		}
	}
	
	for(int i=0,j=0;i<m,j<a.size()-1;i++){
		if(a[j] < a[j+2]){
			a[j]++;
			is[j] = true;
		}
		else j++;
	}
	
	for(int i=0;i<is.size();i++) if(is[i]) num++;
	cout << num;
	//我知道逻辑有问题但是不会改了C艹
	//cout << "战雷有个俄联邦\n";
	//cout << "BVVD爱加强\n";
	//cout << "苏-30 SM制霸天空\n";
	//cout << "BMPT爱杀回马枪\n";
	//cout << "米-28 Z吊射火箭\n";
	//cout << "BMPT创烂地面\n";
	//CCF你敢让我一个打J组的以0.5分只差无缘J组复赛再以1.5分险胜S组复赛哦不不不不不我无疑是愤怒的我整个S组初赛只会一个卡特列数你也能让我蒙过了哦不不不不不你的胆子真是肥嘟嘟的 
	
	return 0;
}
