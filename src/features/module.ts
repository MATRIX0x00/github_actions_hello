export function executeWorkflow() {
  const steps = ['validate', 'transform', 'persist'];
  return steps.map((s) => ({ step: s, status: 'completed' }));
}