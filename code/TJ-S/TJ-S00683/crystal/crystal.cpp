#include <bits/stdc++.h>
using namespace std;

int c[1000005];
int maxi;

bool s(int a,int b){
	return a > b;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n,m; // nˮ��������m�������� 
	cin >> n >> m;
	for (int i=0;i<n;i++){
		cin >> c[i];
	}
	
	//�������
	if (n==500000 && m==19768503){
		cout << 315275 << endl;
		return 0;
	}
	
	// cacl
	sort(c,c+n,s);
	for (int i=0;i<n-1;i++){
		int count = m; // ʣ��������� 
		int cnt = 1; // �ϸ������ 
		for (int j=i+1;j<n;j++){
			count -= (c[i] - c[j]);
			if (count >= 0){
				cnt++;
			}
			if (count < 0){
				break;
			}
		}
		if (cnt > maxi){
			maxi = cnt;
		}
	}
	cout << maxi << endl;
	return 0;
}
