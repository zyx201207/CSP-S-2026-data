#include<bits/stdc++.h>
using namespace std;
int m,n;
vector<int>a;
int shen[300001];
queue<int> dianshu;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        a.push_back(i+1);
    }
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        dianshu.push(x);
    }
    for(int aa=0;aa<n;aa++){
        int ds_long=dianshu.size();
        for(int i=0;i<ds_long;i++){
            for(int j=0;j<a.size();j++){
                if(a[j]==dianshu.front()){
                    a.erase(a.begin()+j,a.end());
                    break;
                }
            }
            a.push_back(dianshu.front());

            dianshu.push(dianshu.front());
            dianshu.pop();
        }
//        for(int j=0;j<a.size();j++){
//                cout<<a[j]<<" ";
//            }
//        cout<<endl;
        for(int i=0;i<a.size();i++){
            shen[a[i]]++;
        }
        a.erase(a.begin(),a.end());
        dianshu.pop();
    }
    for(int i=1;i<=m;i++)
    {
        cout<<shen[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
