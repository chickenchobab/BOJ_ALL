#include <iostream>
#include <algorithm>

using namespace std;

int n, m, ans;
int arr[1001];

bool cmp(int a, int b){
    if (a % 10 == b % 10){
        return a < b;
    }
    return a % 10 < b % 10;
}

void init(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        cin >> arr[i];
    }
}

void solve(){
    sort(arr + 1, arr + n + 1, cmp);
    for (int i = 1; i <= n && m; i ++){
        int tmp = arr[i];
        if (tmp < 10) continue;
        int cut = min(m, tmp / 10 - (tmp % 10 == 0));
        ans += (cut + (tmp - cut * 10 == 10));
        m -= cut;
    }
}

int main(){
    init();
    solve();
    cout << ans;
}