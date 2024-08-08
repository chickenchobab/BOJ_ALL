#include <vector>

using namespace std;

vector<int> answer;
vector<int> ryan(11, 0);
int maxScore = -1;

int calcScoreDiff(const vector<int> &apeach) {
  int scoreApeach = 0;
  int scoreLion = 0;

  for(int i = 0; i < 11; ++i) {
    if(apeach[i] == 0 && ryan[i] == 0) continue;
    if(apeach[i] >= ryan[i]) scoreApeach += 10 - i;
    else scoreLion += 10 - i;
  }

  return scoreLion - scoreApeach;
}

void dfs(const vector<int> &apeach, int score, int arrow) {
  if(score == -1 || arrow == 0) {
    ryan[10] = arrow;
    int scoreDiff = calcScoreDiff(apeach);
    if(scoreDiff > 0 && maxScore < scoreDiff) {
      maxScore = scoreDiff;
      answer = ryan;
    }
    ryan[10] = 0;
    return;
  }

  if(arrow > apeach[score]) {
    ryan[score] = apeach[score] + 1;
    dfs(apeach, score - 1, arrow - apeach[score] - 1);
    ryan[score] = 0;
  }

  dfs(apeach, score - 1, arrow);
}

vector<int> solution(int n, vector<int> info) {
  dfs(info, 10, n);

  if(maxScore == -1) answer.push_back(-1);

  return answer;
}