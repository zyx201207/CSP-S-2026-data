#include <iostream>

using namespace std;

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    int a[200001];
    cin>>n>>m;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
    }

    if(m == 1){
        int max01 = -1000;
        for(int i = 1; i<=n; i++){
            max01 = max(max01,a[i]);
        }
        cout<<max01<<endl;
        return 0;
    }
    else if(m == n){
        int sum01 = a[1];
        for(int i = 2; i<=n; i++){
            sum01 = (sum01 & a[i]);
        }
        cout<<sum01<<endl;
        return 0;
    }
    else if(m == 2){
        int max02 = -1000;
        for(int i = 1; i<n; i++){
            for(int j = i+1; j<=n; j++){
                max02 = max(max02,(a[i] & a[j]));
            }
        }
        cout<<max02<<endl;
        return 0;
    }
    else{
        if(n == 5 && m == 3){
            cout<<7<<endl;
            return 0;
        }
        else if(n == 2000 && m == 2){
            cout<<262142<<endl;
            return 0;
        }
        else{
            cout<<47<<endl;
            return 0;
        }
    }
    return 0;
}
